[@bs.module] external hello : ReasonReact.reactClass = "./Hello.react";

[@bs.deriving abstract]
type jsProps = {selectedDayStr: string};

let make = (~selectedDay: option(DayUtil.day), ~todayStr: string, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=hello,
    ~props=
      jsProps(
        ~selectedDayStr=DayUtil.selectDateTxt((selectedDay, todayStr)),
      ),
    children,
  );