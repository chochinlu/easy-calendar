// Generated by BUCKLESCRIPT VERSION 4.0.3, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("Days");

function dayText(day) {
  switch (day) {
    case 0 : 
        return "Sun";
    case 1 : 
        return "Mon";
    case 2 : 
        return "Tue";
    case 3 : 
        return "Wed";
    case 4 : 
        return "Thu";
    case 5 : 
        return "Fri";
    case 6 : 
        return "Sat";
    
  }
}

function dayEle(day) {
  return React.createElement("div", {
              className: "col-sm card"
            }, day);
}

var dayList = $$Array.map(dayEle, $$Array.map(dayText, /* array */[
          /* Sun */0,
          /* Mon */1,
          /* Tue */2,
          /* Wed */3,
          /* Thu */4,
          /* Fri */5,
          /* Sat */6
        ]));

function make() {
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
          /* render */(function () {
              return React.createElement("div", {
                          className: "container"
                        }, React.createElement("div", {
                              className: "row"
                            }, dayList));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.dayText = dayText;
exports.dayEle = dayEle;
exports.dayList = dayList;
exports.make = make;
/* component Not a pure module */