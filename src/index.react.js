import React from "react";
import ReactDOM from "react-dom";

const Calendar = require("./Calendar.bs").jsComponent;

const element = <Calendar />;
ReactDOM.render(element, document.getElementById("app"));
