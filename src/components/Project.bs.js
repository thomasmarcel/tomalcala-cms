// Generated by BUCKLESCRIPT VERSION 5.0.3, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");

function str(prim) {
  return prim;
}

function Project(Props) {
  var project = Props.project;
  Props.index;
  return React.createElement("div", {
              className: "card"
            }, React.createElement("div", {
                  className: "card-image"
                }, React.createElement("figure", {
                      className: "image is-4by3"
                    }, React.createElement("img", {
                          alt: "Placeholder image",
                          src: project.image
                        }))), React.createElement("div", {
                  className: "card-content"
                }, React.createElement("div", {
                      className: "media"
                    }, React.createElement("div", {
                          className: "media-left"
                        }, React.createElement("figure", {
                              className: "image is-48x48"
                            }, React.createElement("img", {
                                  alt: "Placeholder image",
                                  src: project.thumbnail
                                }))), React.createElement("div", {
                          className: "media-content"
                        }, React.createElement("p", {
                              className: "title is-4"
                            }, project.title), React.createElement("p", {
                              className: "subtitle is-6"
                            }, React.createElement("a", {
                                  href: project.url,
                                  target: "_blank"
                                }, project.url)))), React.createElement("div", {
                      className: "content"
                    }, project.tagline, React.createElement("br", undefined), "Release Date: " + project.date)));
}

var make = Project;

var $$default = Project;

exports.str = str;
exports.make = make;
exports.$$default = $$default;
exports.default = $$default;
exports.__esModule = true;
/* react Not a pure module */
