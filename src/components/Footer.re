let str = ReasonReact.string;

/* let component = ReasonReact.statelessComponent("Footer"); */
[@react.component]
let make = () => {
  <footer className="footer"
    style=(ReactDOMRe.Style.make(~borderTop="0", ()))
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
let default = make;
