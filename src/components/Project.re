let str = ReasonReact.string;

[@bs.deriving abstract]
type project = {
  title: string,
  date: string,
  url: string,
  tagline: string,
  position: string,
  description: string
};

[@react.component]
let make = (~project: project, ~index: int) => {
  <div className="card">
    <div className="card-image">
      <figure className="image is-4by3">
        <img src="https://bulma.io/images/placeholders/1280x960.png"
        alt="Placeholder image" />
      </figure>
    </div>
    <div className="card-content">
      <div className="media">
        <div className="media-left">
          <figure className="image is-48x48">
            <img src="https://bulma.io/images/placeholders/96x96.png"
            alt="Placeholder image" />
          </figure>
        </div>
        <div className="media-content">
          <p className="title is-4">(str(project->titleGet))</p>
          <p className="subtitle is-6">
            <a href=(project->urlGet) target="_blank">
              (str(project->urlGet))
            </a>
          </p>
        </div>
      </div>

      <div className="content">
        (str(project->taglineGet))
        <br />
        (str("Release Date: " ++ project->dateGet))
      </div>
    </div>
  </div>
};

let default = make;
