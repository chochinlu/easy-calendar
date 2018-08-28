type day = {
  year: int,
  month: int,
  date: int,
  str: string,
};

let floatStr = str => str |> int_of_float |> string_of_int;

let getDayStr = (year, month, date) =>
  string_of_int(year)
  ++ "-"
  ++ string_of_int(month)
  ++ "-"
  ++ string_of_int(date);

let dayInfo = (someDay: Js.Date.t) : day => {
  let year = someDay |> Js.Date.getUTCFullYear |> int_of_float;
  let month = someDay |> (d => Js.Date.getUTCMonth(d) +. 1.0) |> int_of_float;
  let date = someDay |> Js.Date.getDate |> int_of_float;
  let dayStr = getDayStr(year, month, date);

  {year, month, date, str: dayStr};
};