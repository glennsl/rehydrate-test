
let pluralize noun count =>
  count === 1 ? noun : noun ^ "s";

let default value => fun
| Some x => x
| None => value;

let classNames items =>
  items
  |> List.map (fun (name, flag) => flag ? name : "")
  |> List.filter (fun s => s !== "")
  |> String.concat " ";

let mkDict entries => {
  let set dict (key, value) => {
    ignore (Js.Dict.set dict key value);
    dict
  };
  List.fold_left set (Js.Dict.empty ()) entries;
};

type location;
external location: location = "window.location" [@@bs.val];
external setHash: location => string => unit = "hash" [@@bs.set];

let gotoHash value =>
  setHash location ("#/" ^ value);
