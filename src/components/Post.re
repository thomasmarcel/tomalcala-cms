open Gatsby;

let str = ReasonReact.string;

[@bs.deriving abstract]
type frontmatter = {
  date: string,
  templateKey: string,
  title: string
};

[@bs.deriving abstract]
type fields = {
  slug: string
};

[@bs.deriving abstract]
type post = {
  excerpt: string,
  frontmatter: frontmatter,
  fields: fields,
  id: string
};

/* This is the basic component. */
let component = ReasonReact.statelessComponent("Post");

[@bs.deriving abstract]
type jsProps = {
  post: post,
  index: int,
};

let make = (~post, ~index, _children) => {
  ...component,
  render: _self => {
    <div>
      <div className=("bg-image bg" ++ string_of_int(index))>
        <div className="layer opacity-dark" />
      </div>
      <div
        className="content"
        style=(ReactDOMRe.Style.make(~borderBottom="1px solid #333",
                                     ~padding="2em 4em",
                                     ~position="relative", ()))
        key=(post->idGet)
      >
        <p>
          <Link className="has-text-light bold"
          href=(post->fieldsGet->slugGet) >
            (str(post->frontmatterGet->titleGet))
          </Link>
        </p>
        <p>
          (str(post->excerptGet))
        </p>
        <div className="columns">
          <div className="column">
            <Link className="btn parallelogram has-background-link"
              href=(post->fieldsGet->slugGet) >
              <div className="skew-fix">
                (str("Read More"))
                <i className="fas fa-caret-right"
                style=(ReactDOMRe.Style.make(~marginLeft="10px", ())) ></i>
              </div>
            </Link>
          </div>
          <div className="column">
            <div className="is-pulled-right">
              <span className="tag is-link is-medium">
                <i className="far fa-clock" />
                <small style=(ReactDOMRe.Style.make(~marginLeft="10px", ())) >
                  (str(post->frontmatterGet->dateGet))
                </small>
              </span>
            </div>
          </div>
        </div>
      </div>
    </div>
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~post=jsProps->postGet,
      ~index=jsProps->indexGet,
      [||],
    )
  );
