let str = ReasonReact.string;

/* This is the basic component. */
let component = ReasonReact.statelessComponent("Footer");

/* Your familiar handleClick from ReactJS. This mandatorily takes the payload,
   then the `self` record, which contains state (none here), `handle`, `reduce`
   and other utilities */
/* let handleClick = (_event, _self) => Js.log("clicked!"); */

/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Component1 message="hello" />`

   Which desugars to

   `ReasonReact.element(Component1.make(~message="hello", [||]))` */
let make = (_children) => {
  ...component,
  render: _self =>
    /* <div onClick={self.handle(handleClick)}> */
    /*   {ReasonReact.string(message)} */
    /* </div>, */
    <div>
      <Social
        linkedin="https://www.linkedin.com/in/talcala"
        github="https://github.com/ThomasMarcel"
        slack="https://tomalcala.slack.com"
        twitter="https://twitter.com/ThomasAlcala"
        skype="https://join.skype.com/invite/xfKeFzPFWsND"
      />
      <footer className="footer"
        style=(ReactDOMRe.Style.make(~borderTop="1px solid #333", ()))
      >
        <div className="content has-text-centered">
          <p>
            <strong>
              <i className="far fa-copyright" />
              (str("TomAlcala"))
            </strong>
            (str(" Blog and Sandbox by "))
            <a href="https://github.com/ThomasMarcel" target="_blank">
              (str("Thomas Alcala Schneider"))
            </a>
            (str("."))
          </p>
        </div>
      </footer>
    </div>
};

/* [@bs.deriving abstract] */
/* type jsProps = { */
/*   message: string, */
/* }; */

let default =
  ReasonReact.wrapReasonForJs(~component, _jsProps =>
    make(
      /* ~message=jsProps->messageGet, */
      [||],
    )
  );
