// Generated by BUCKLESCRIPT VERSION 4.0.3, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Days$ReactTemplate = require("./Days.bs.js");
var Cells$ReactTemplate = require("./Cells.bs.js");
var Header$ReactTemplate = require("./Header.bs.js");

function floatStr(str) {
  return String(str | 0);
}

function getDayStr(year, month, date) {
  return String(year) + ("-" + (String(month) + ("-" + String(date))));
}

function dayInfo(someDay) {
  var year = someDay.getUTCFullYear() | 0;
  var month = someDay.getUTCMonth() + 1.0 | 0;
  var date = someDay.getUTCDate() | 0;
  var dayStr = getDayStr(year, month, date);
  return /* record */[
          /* year */year,
          /* month */month,
          /* date */date,
          /* str */dayStr
        ];
}

var today = dayInfo(new Date());

var component = ReasonReact.reducerComponent("Calendar");

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
          /* render */(function (self) {
              return React.createElement("div", {
                          className: "bordered responsive-margin"
                        }, ReasonReact.element(undefined, undefined, Header$ReactTemplate.make(today[/* str */3], (function () {
                                    return Curry._1(self[/* send */3], /* Show */0);
                                  }), self[/* state */1][/* show */0], self[/* state */1][/* currentMonth */1], (function () {
                                    return Curry._1(self[/* send */3], /* PrevMonth */1);
                                  }), (function () {
                                    return Curry._1(self[/* send */3], /* NextMonth */2);
                                  }), /* array */[])), ReasonReact.element(undefined, undefined, Days$ReactTemplate.make(/* array */[])), ReasonReact.element(undefined, undefined, Cells$ReactTemplate.make(/* array */[])));
            }),
          /* initialState */(function () {
              return /* record */[
                      /* show */false,
                      /* currentMonth */today[/* month */1]
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              switch (action) {
                case 0 : 
                    return /* Update */Block.__(0, [/* record */[
                                /* show */!state[/* show */0],
                                /* currentMonth */state[/* currentMonth */1]
                              ]]);
                case 1 : 
                    return /* Update */Block.__(0, [/* record */[
                                /* show */state[/* show */0],
                                /* currentMonth */state[/* currentMonth */1] - 1 | 0
                              ]]);
                case 2 : 
                    return /* Update */Block.__(0, [/* record */[
                                /* show */state[/* show */0],
                                /* currentMonth */state[/* currentMonth */1] + 1 | 0
                              ]]);
                
              }
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.floatStr = floatStr;
exports.getDayStr = getDayStr;
exports.dayInfo = dayInfo;
exports.today = today;
exports.component = component;
exports.make = make;
/* today Not a pure module */
