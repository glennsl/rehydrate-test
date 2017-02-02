module ClearButton = {
  let createElement ::onClick ::children () =>
    <button className="clear-completed" onClick=onClick>
      (ReactRe.stringToElement "Clear completed")
    </button>;
};

module NodoFooter = {
  include ReactRe.Component;
  let name = "NodoFooter";

  type props = {
    items: list NodoItem.t,
    filter: Filter.t,
    onFilterChanged: Filter.t => unit,
    onClearCompleted: ReactRe.event => unit
  };

  let render {props, updater} => {
    let completedCount = props.items |> List.filter (fun item => NodoItem.(item.completed)) |> List.length;
    let activeCount = (List.length props.items) - completedCount;

    <footer className="footer">
      <span className="todo-count">
        <strong> (ReactRe.stringToElement (string_of_int activeCount)) </strong>
        (ReactRe.stringToElement ((Utils.pluralize " item" activeCount) ^ " left"))
      </span>

      <Filters selected=props.filter onSelect=props.onFilterChanged/>

      (completedCount > 0 ?
        (<ClearButton onClick=props.onClearCompleted />) :
        ReactRe.nullElement)
    </footer>;
  }
};

include ReactRe.CreateComponent NodoFooter;
let createElement ::items ::filter ::onFilterChanged ::onClearCompleted ::children =>
  wrapProps { items, filter, onFilterChanged, onClearCompleted } ::children;
