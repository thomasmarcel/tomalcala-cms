let str = ReasonReact.string;

let component = ReasonReact.statelessComponent("Social");

[@react.component]
let make = (~linkedin, ~github, ~twitter, ~slack, ~skype, _children) => {
  <div
    style=(ReactDOMRe.Style.make(~backgroundColor="#c3e88d", ()))
  >
    <div
      className="content"
      style=(ReactDOMRe.Style.make(~borderBottom="0",
                                   ~padding="2em 4em",
                                   ~position="relative", ()))
    >
      <div className="columns">
        <div className="column has-text-centered">
          <a className="social" href=(linkedin) target="_blank">
            <i className=("fa-3x fab fa-linkedin") />
          </a>
        </div>
        <div className="column has-text-centered">
          <a className="social" href=(github) target="_blank">
            <i className=("fa-3x fab fa-github-square") />
          </a>
        </div>
        <div className="column has-text-centered">
          <a className="social" href=(slack) target="_blank">
            <i className=("fa-3x fab fa-slack") />
          </a>
        </div>
        <div className="column has-text-centered">
          <a className="social" href=(skype) target="_blank">
            <i className=("fa-3x fab fa-skype") />
          </a>
        </div>
        <div className="column has-text-centered">
          <a className="social" href=(twitter) target="_blank">
            <i className=("fa-3x fab fa-twitter-square") />
          </a>
        </div>
      </div>
    </div>
  </div>
};

let default = make;
