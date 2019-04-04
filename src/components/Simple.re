open Gatsby;

let str = ReasonReact.string;

/* This is the basic component. */
let component = ReasonReact.statelessComponent("Simple");

[@bs.deriving abstract]
type jsProps = {
  title: string,
  body: string,
  direction: string,
  icon: string,
  background: string,
  action: string,
};

let make = (~title, ~body, ~direction, ~icon, ~background, ~action, _children) => {
  ...component,
  render: _self => {
    <div>
      <div className=("bg-image " ++ background)
        style=(ReactDOMRe.Style.make(~maxHeight="241px", ()))
      >
        <div className="layer opacity-dark" />
      </div>
      <div
        className="content"
        style=(ReactDOMRe.Style.make(~borderBottom="1px solid #333",
                                     ~padding="2em 4em",
                                     ~position="relative", ()))
      >
        <div className="columns">
          <div className="column">
            <h1>(str(title))</h1>
            <p>
              (str(body))
            </p>
            <a className="btn parallelogram has-background-link"
              href=(action) >
              <div className="skew-fix">
                (str("Read More"))
                <i className="fas fa-caret-right"
                style=(ReactDOMRe.Style.make(~marginLeft="10px", ())) ></i>
              </div>
            </a>
          </div>
          <div className="column">
            <h1 className="is-centered">
              <i className=("fa-5x " ++ icon) />
            </h1>
          </div>
        </div>
      </div>
    </div>
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~title=jsProps->titleGet,
      ~body=jsProps->bodyGet,
      ~direction=jsProps->directionGet,
      ~icon=jsProps->iconGet,
      ~background=jsProps->backgroundGet,
      ~action=jsProps->actionGet,
      [||],
    )
  );
