
module Filters = {
  include ReactRe.Component;
  let name = "Filters";

  type props = {
    selected: Filter.t,
    onSelect: Filter.t => unit
  };


  let render {props, updater} => {
    let mkListItem filter =>
      <li key=(Filter.toString filter) onClick=(fun e => props.onSelect filter)>
        <a className=(props.selected === filter ? "selected" : "")> (ReactRe.stringToElement (Filter.toString filter)) </a>
      </li>;

    <ul className="filters">
      (ReactRe.arrayToElement (Filter.list |> (List.map mkListItem) |> Array.of_list))
    </ul>
  };
};

include ReactRe.CreateComponent Filters;
let createElement ::selected ::onSelect ::children =>
  wrapProps { selected, onSelect } ::children;
