import React from "react";
import ReactDOM from "react-dom";

const Calendar = require("./Calendar.bs").jsComponent;
// const Days = require("./Days.bs").jsComponent;

const element = <Calendar />;
// const element = <Days />;

ReactDOM.render(element, document.getElementById("app"));
