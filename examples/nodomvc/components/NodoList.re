module NodoList = {
  include ReactRe.Component;
  let name = "NodoList";

  type props = {
    items: list NodoItem.t,
    filter: Filter.t,
    selected: option string
  };

  let render {props, updater} => {
    let mkNodoItem item =>
      <NodoItem
        key=item.id
        item
        selected=
          (switch props.selected {
          | None => false
          | Some id => id === item.id
          })
        onToggle=(fun e => ())
        onDestroy=(fun e => ())
      />;

    <ul className="todo-list">
      (props.items
      |> List.filter (
        fun item => switch props.filter {
          | All => true
          | Active => not NodoItem.(item.completed)
          | Completed => NodoItem.(item.completed)
        })
      |> List.map mkNodoItem
      |> Array.of_list
      |> ReactRe.arrayToElement)
    </ul>
  };
};

include ReactRe.CreateComponent NodoList;
let createElement ::items ::filter ::selected ::children =>
  wrapProps { items, filter, selected } ::children;
