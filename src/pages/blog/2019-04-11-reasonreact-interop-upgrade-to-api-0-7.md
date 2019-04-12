---
templateKey: blog-post
title: ReasonReact Upgrade to 0.7 (for JS interop)
date: 2019-04-12T02:25:57.988Z
description: Rewriting ReasonReact components called from ReactJS components.
tags:
  - React
  - ReasonReact
  - ReasonML
  - BuckleScript
---
Hey!

So as you may know, ReasonReact 0.7 is out! And it looks really awesome and a lot better at interacting with JS code, which is a GREAT idea, as it was kinda tricky to work with, the wrapping for JS was sketchy, as were props, and the overall look of the stateless and reducer components was going in a different direction than ReactJS update.

So now the new ReasonReact is out, using ReactJS hooks instead of the "deprecated" "Record API" as the ReasonReact people call the old syntax and bindings. This is cool, but raised some concerns in my mind as to how to upgrade my old components, and as expected, there isn't an automated way to do so because of the significant differences between both APIs.

I personally have a bunch of projects using Gatsby and Next.js frameworks with components written in ReasonReact that are at a state of active development, or post production features and enhancements stage, so I had to upgrade them. I am going to detail how I did so at a project and component scope, for future reference.

## Upgrade the Modules

First of all, let's upgrade the modules in `package.json`.

Locate the `bs-platform` module reference in `devDependencies`, and bump up the version to v5:

```
  "devDependencies": {  
    "bs-platform": "^5.0.1",  
```

And under the `dependencies`, bump up `react`, `react-dom` and `reason-react`:

```
  "dependencies": {  
    "react": "^16.8.1",  
    "react-dom": "^16.8.1",  
    "reason-react": ">=0.7.0"    
```

And install (`$ npm run install` or `$ yarn install`). This takes care of the project scope changes. Now let's get into details in components.

## Stateless Components

Of course, the simplest components to upgrade are stateless components. And it's actually kind of nice to start with those, as it actually results in removing the sketchy `wrapReasonforJS` and `jsProps` code. Let's start with an example of previous code, detail the elements that changed, and get into the new API syntax.

So here's an old component syntax, it takes a prop called github, supposed to be a URL, and display it as a link with an icon:

```
let str = ReasonReact.string;

let component = ReasonReact.statelessComponent("Social");

[@bs.deriving abstract]
type jsProps = {
  github: string,
};

let make = (~github, _children) => {
  ...component,
  render: _self => {
    <div
      style=(ReactDOMRe.Style.make(~backgroundColor="#002266", ()))
    >
      <div
        className="content"
        style=(ReactDOMRe.Style.make(~borderBottom="1px solid #333",
                                     ~padding="2em 4em",
                                     ~position="relative", ()))
      >
        <div className="columns">
          <div className="column has-text-centered">
            <a className="social" href=(github) target="_blank">
              <i className=("fa-3x fab fa-github-square") />
            </a>
          </div>
        </div>
      </div>
    </div>
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~github=jsProps->githubGet,
      [||],
    )
  );
```

What's noteworthy here:

The component and its props type definition

```
let component = ReasonReact.statelessComponent("Social");

[@bs.deriving abstract]
type jsProps = {
  github: string,
};
```

Then the make function, taking the props, extending the component and adding a render function

```
let make = (~github, _children) => {
  ...component,
  render: _self => {
    <div>
      [...]
    </div>
  }
};
```

And then the sketchy wrapping to make the component importable in a ReactJS component with the JS ES6 syntax. The `default` constant is a way to be able to export the make function as the default function.

```
let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~github=jsProps->githubGet,
      [||],
    )
  );
```

The syntax is sketchy because far from instinctive or guessable. Now let's look at the ReasonReact 0.7 API syntax:

```
let str = ReasonReact.string;

[@react.component]
let make = (~github) => {
  <div
    style=(ReactDOMRe.Style.make(~backgroundColor="#002266", ()))
  >
    <div
      className="content"
      style=(ReactDOMRe.Style.make(~borderBottom="1px solid #333",
                                   ~padding="2em 4em",
                                   ~position="relative", ()))
    >
      <div className="columns">
        <div className="column has-text-centered">
          <a className="social" href=(github) target="_blank">
            <i className=("fa-3x fab fa-github-square") />
          </a>
        </div>
      </div>
    </div>
  </div>
};

let default = make;
```

First of all, the component and its props type definition are removed! Yeah, completely! Actually the component constant is replaced by a decorator later, that's the next point. Look at this bit of code:

```
[@react.component]
let make = (~github) => {
  <div>
    [...]
  </div>
};
```

The `make` function loses the `children` attribute and only contains the props. There's also no more `render` function in it, so the JSX content is one encapsulation closer to the root of the function. What is added and replace the component constant declaration of old is the `[@react.component]` decorator directly above the `make` function declaration.

```
let default = make;
```

Finally, the `let default = make;` allows the function to be exported as default.

## Reducer Components

Here let's take the component from the old documentation. I do have some real world examples, but they're too big and might confuse more than anything. So here's the reducer component as the deprecated Record API describes:

```
type state = {
  count: int,
  show: bool,
};

type action =
  | Click
  | Toggle;[@bs.deriving abstract]
type jsProps = {
  greeting: string,
};

let component = ReasonReact.reducerComponent("Example");

let make = (~greeting, _children) => {
  ...component,

  initialState: () => {count: 0, show: true},

  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Toggle => ReasonReact.Update({...state, show: !state.show})
    },

  render: self => {
    let message =
      "You've clicked this " ++ string_of_int(self.state.count) ++ " times(s)";
    <div>
      <button onClick=(_event => self.send(Click))>
        (ReasonReact.string(message))
      </button>
      <button onClick=(_event => self.send(Toggle))>
        (ReasonReact.string("Toggle greeting"))
      </button>
      (
        self.state.show
          ? ReasonReact.string(greeting)
          : ReasonReact.null
      )
    </div>;
  },
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~greeting=jsProps->greetingGet,
      [||],
    )
  );
```

It was mostly pretty straightforward, except what was already mentioned for the stateless components. Here is the new version of it:

```
[@react.component]
let make = (~greeting) => {
  let (count, setCount) = React.useState(() => 0);
  let (show, setShow) = React.useState(() => true);

  let message = "You've clicked this " ++ string_of_int(count) ++ " times(s)";

  <div>
    <button onClick={_event => setCount(_count => count + 1)} >
      (React.string(message))
    </button>
    <button onClick={_event => setShow(_show => !show)}>
      (React.string("Toggle greeting"))
    </button>
    (
      show
        ? React.string(greeting)
        : React.null
    )
  </div>
};

let default = make;
```

Shorter and cleaner. Let's analyze it.

First of all, the state and action types are removed, same as the component definition.

```
type state = {
  count: int,
  show: bool,
};

type action =
  | Click
  | Toggle;[@bs.deriving abstract]
type jsProps = {
  greeting: string,
};

let component = ReasonReact.reducerComponent("Example");
```

Same as before, the make function now has a decorator above, and the `...component` extension is removed.

```
[@react.component]
let make = (~greeting) => {
```

And now the state attributes and setters definition, so instead of having the state type

```
type state = {
  count: int,
  show: bool,
};
```

And the initial state value setting

```
initialState: () => {count: 0, show: true},
```

We have one line per attribute, that defines the variable, the setter, the default value from which the variable type is inferred:

```
  let (count, setCount) = React.useState(() => 0);
  let (show, setShow) = React.useState(() => true);
```

Cool!

So now all that was using the state attributes like `self.state.count`, as in the snippet below

```
    let message =
      "You've clicked this " ++ string_of_int(self.state.count) ++ " times(s)";
```

Now uses the variable name directly:

```
let message = "You've clicked this " ++ string_of_int(count) ++ " times(s)";
```

And the syntax of for click events also changed in the JSX code, we went from sending an action from the action type enum to the reducer function

```
<button onClick=(_event => self.send(Click))>
```

To a more straightforward call to the setter. Also note the use of brackets instead of parenthesis

```
<button onClick={_event => setCount(_count => count + 1)} >
```

And as before for stateless components, all the wrapping for JS is removed, so all the code below

```
let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~greeting=jsProps->greetingGet,
      [||],
    )
  );
```

is replaced by a simple default declaration:

```
let default = make;
```
And this is it!
