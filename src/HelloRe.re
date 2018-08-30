[@bs.module] external hello : ReasonReact.reactClass = "./Hello.react";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass=hello, ~props=None, children);