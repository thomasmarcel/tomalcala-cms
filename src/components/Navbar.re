let str = ReasonReact.string;

let github = "../img/github-icon.svg";

/* This is the basic component. */
let component = ReasonReact.statelessComponent("Navbar");

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
    <nav className="navbar is-transparent" role="navigation" ariaLabel="main-navigation">
      <div className="container">
        <div className="navbar-brand">
          <Gatsby.Link href="/" className="navbar-item" title="Logo">
            <i className="fab fa-empire fa-2x" />
            (str("TomAlcala"))
          </Gatsby.Link>
          <div className="navbar-burger burger" data="navMenu">
            <span></span>
            <span></span>
            <span></span>
          </div>
        </div>
        <div id="navMenu" className="navbar-menu">
        <div className="navbar-start has-text-centered">
          <a className="navbar-item" href="/about">
            (str("About"))
          </a>
          <a className="navbar-item" href="/contact">
            (str("Contact"))
          </a>
          <a className="navbar-item" href="/img/thomas_alcala-cv-201901-en-m.pdf" target="_blank">
            (str("Resume"))
          </a>
        </div>
        <div className="navbar-end has-text-centered">
          <a
            className="navbar-item"
            href="https://github.com/ThomasMarcel/tomalcala-cms"
            target="_blank"
            rel="noopener noreferrer"
          >
            <span>(str("Curious About the Source Code?"))</span>
            <span className="icon">
              <img src=(github) alt="Github" />
            </span>
          </a>
        </div>
        </div>
      </div>
    </nav>
};

/* [@bs.deriving abstract] */
/* type jsProps = { */
/*   message: string, */
/* }; */

/* let default = */
/*   ReasonReact.wrapReasonForJs(~component, _jsProps => */
/*     make( */
/*       /1* ~message=jsProps->messageGet, *1/ */
/*       [||], */
/*     ) */
/*   ); */

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
