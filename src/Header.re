let component = ReasonReact.statelessComponent("Header");

let yearMonth = (year: int, month: int) : string =>
  (year |> string_of_int) ++ "-" ++ (month |> string_of_int);

let selectDateTxt = ((someDay: option(DayUtil.day), todayStr)) => {
  let dayStr =
    switch (someDay) {
    | None => todayStr
    | Some(day) => day.str
    };
  "Selected date: " ++ dayStr;
};

let make =
    (
      ~todayStr,
      ~currentMonth,
      ~currentYear,
      ~selectedDate,
      ~clickPrev,
      ~clickNext,
      ~clickCurrent,
      _children,
    ) => {
  ...component,
  render: _self =>
    <div>
      <p> (todayStr |> (t => "Today" ++ t |> ReasonReact.string)) </p>
      <p>
        ((selectedDate, todayStr) |> selectDateTxt |> ReasonReact.string)
      </p>
      <h2> (yearMonth(currentYear, currentMonth) |> ReasonReact.string) </h2>
      <button onClick=clickPrev>
        (ReasonReact.string("< Prev month"))
      </button>
      <button onClick=clickCurrent>
        (ReasonReact.string("This month"))
      </button>
      <button onClick=clickNext>
        (ReasonReact.string("Next month >"))
      </button>
    </div>,
};