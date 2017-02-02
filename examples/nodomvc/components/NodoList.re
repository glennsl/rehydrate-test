module NodoList = {
  include ReactRe.Component;
  let name = "NodoList";

  type props = {
    items: list Todo.t,
    filter: Filter.t,
    selected: option string,
    store: Store.t
  };

  let render {props, updater} => {
    let { items, filter, selected, store } = props;
    let mkNodoItem item =>
      <NodoItem
        key=item.id
        item
        selected=
          (switch selected {
          | None => false
          | Some id => id === item.id
          })
        store
      />;

    <ul className="todo-list">
      (items
      |> List.filter (
        fun item => switch filter {
          | All => true
          | Active => not Todo.(item.completed)
          | Completed => Todo.(item.completed)
        })
      |> List.map mkNodoItem
      |> Array.of_list
      |> ReactRe.arrayToElement)
    </ul>
  };
};

include ReactRe.CreateComponent NodoList;
let createElement ::items ::filter ::selected ::store ::children =>
  wrapProps { items, filter, selected, store } ::children;
