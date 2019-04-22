open Gatsby;

let str = ReasonReact.string;

[@react.component]
let make = (~title, ~body, ~direction, ~icon, ~background, ~action, _children) => {
  <div>
    <div className=("bg-image " ++ background)
      style=(ReactDOMRe.Style.make(~maxHeight="241px", ()))
    >
      <div className="layer opacity-dark" />
    </div>
    <div
      className="content"
      style=(ReactDOMRe.Style.make(~borderBottom="0",
                                   ~padding="2em 4em",
                                   ~position="relative", ()))
    >
      <div className="columns">
        <div className="column">
          <h1>(str(title))</h1>
          <p>
            (str(body))
          </p>
          <Link className="btn parallelogram action"
            href=(action) >
            <div className="skew-fix">
              (str("Read More"))
              <i className="fas fa-caret-right"
              style=(ReactDOMRe.Style.make(~marginLeft="10px", ())) ></i>
            </div>
          </Link>
        </div>
        <div className="column">
          <h1 className="is-centered">
            <i className=("fa-5x " ++ icon) />
          </h1>
        </div>
      </div>
    </div>
  </div>
};

let default = make;
