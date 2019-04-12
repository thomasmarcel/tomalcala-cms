---
templateKey: blog-post
title: ReasonReact Interop Upgrade to API 0.7
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
