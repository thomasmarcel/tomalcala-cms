let str = ReasonReact.string;

/* This is the basic component. */
let component = ReasonReact.statelessComponent("Social");

[@bs.deriving abstract]
type jsProps = {
  linkedin: string,
  github: string,
  twitter: string,
  slack: string,
  skype: string,
};

let make = (~linkedin, ~github, ~twitter, ~slack, ~skype, _children) => {
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
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~linkedin=jsProps->linkedinGet,
      ~github=jsProps->githubGet,
      ~twitter=jsProps->twitterGet,
      ~slack=jsProps->slackGet,
      ~skype=jsProps->skypeGet,
      [||],
    )
  );
