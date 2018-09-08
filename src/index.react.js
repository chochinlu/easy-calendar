import React from "react";
import ReactDOM from "react-dom";

// import { jsComponent as Calendar } from "./Calendar.bs";
// import { Calendar } from "./IndexLib";
import { Calendar } from "../build/IndexLib";

// const Days = require("./Days.bs").jsComponent;

const element = <Calendar />;
// const element = <Days />;

ReactDOM.render(element, document.getElementById("app"));
