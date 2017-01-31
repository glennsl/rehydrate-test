type filter =
| All
| Active
| Completed;

let filters = [All, Active, Completed];

let filterToString = fun
| All => "All"
| Active => "Active"
| Completed => "Completed";

module Filters = {
  include ReactRe.Component;
  let name = "Filters";

  type props = {
    selected: filter
  };

  let render {props, updater} =>
      <ul className="filters">
        (ReactRe.arrayToElement (filters |> List.map (fun filter =>
          <li>
            <a href="#/" className=(props.selected === filter ? "selected" : "")> (ReactRe.stringToElement (filterToString filter)) </a>
          </li>
        ) |> Array.of_list))
      </ul>
};

include ReactRe.CreateComponent Filters;

let createElement ::selected ::children => wrapProps { selected: selected } ::children;
