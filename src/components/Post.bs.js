// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Gatsby$ReactTemplate = require("../bindings/Gatsby.bs.js");

function str(prim) {
  return prim;
}

var component = ReasonReact.statelessComponent("Post");

function make(post, index, _children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (_self) {
              return React.createElement("div", {
                          key: post.id,
                          className: "content bg bg" + String(index),
                          style: {
                            borderBottom: "1px solid #333",
                            padding: "2em 4em"
                          }
                        }, React.createElement("p", undefined, ReasonReact.element(undefined, undefined, Gatsby$ReactTemplate.Link[/* make */0](post.fields.slug, "has-text-light bold", undefined, /* array */[post.frontmatter.title]))), React.createElement("p", undefined, post.excerpt), React.createElement("div", {
                              className: "columns"
                            }, React.createElement("div", {
                                  className: "column"
                                }, ReasonReact.element(undefined, undefined, Gatsby$ReactTemplate.Link[/* make */0](post.fields.slug, "btn parallelogram has-background-link", undefined, /* array */[React.createElement("div", {
                                                className: "skew-fix"
                                              }, "Read More", React.createElement("i", {
                                                    className: "fas fa-caret-right",
                                                    style: {
                                                      marginLeft: "10px"
                                                    }
                                                  }))]))), React.createElement("div", {
                                  className: "column"
                                }, React.createElement("div", {
                                      className: "is-pulled-right"
                                    }, React.createElement("i", {
                                          className: "far fa-clock"
                                        }), React.createElement("small", undefined, "  " + post.frontmatter.date)))));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

var $$default = ReasonReact.wrapReasonForJs(component, (function (jsProps) {
        return make(jsProps.post, jsProps.index, /* array */[]);
      }));

exports.str = str;
exports.component = component;
exports.make = make;
exports.$$default = $$default;
exports.default = $$default;
exports.__esModule = true;
/* component Not a pure module */
