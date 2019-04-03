module Link = {
  [@bs.module "gatsby"] external link: ReasonReact.reactClass = "Link";
  let make =
      (
        ~href=?,
        ~className=?,
        ~title=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=link,
      ~props=
        Js.Undefined.{
          "to": fromOption(href),
          "className": fromOption(className),
          "title": fromOption(title),
        },
      children,
    );
};

/* module Head = { */
/*   [@bs.module "next/head"] external head: ReasonReact.reactClass = "default"; */
/*   let make = children => ReasonReact.wrapJsForReason(~reactClass=head, ~props=Js.Obj.empty(), children); */
/* }; */

/* module Error = { */
/*   [@bs.module "next/error"] external error: ReasonReact.reactClass = "default"; */
/*   let make = (~statusCode: int, children) => */
/*     ReasonReact.wrapJsForReason(~reactClass=error, ~props={"statusCode": statusCode}, children); */
/* }; */
