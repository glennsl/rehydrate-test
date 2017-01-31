module NodoFooter = {
  include ReactRe.Component;
  let name = "NodoFooter";

  type props = {
    items: list NodoItem.item,
    onClearCompleted: ReactRe.event => unit
  };

  let render {props, updater} => {
    let completedCount = props.items |> List.filter (fun item => NodoItem.(item.completed)) |> List.length;
    let activeCount = (List.length props.items) - completedCount;

    let clearButton =
      completedCount > 0 ?
        <button className="clear-completed" onClick=props.onClearCompleted>
          (ReactRe.stringToElement "Clear completed")
        </button> :
        ReactRe.nullElement;

    let filter: Filters.filter = All;

    <footer className="footer">
      <span className="todo-count">
        <strong> (ReactRe.stringToElement (string_of_int activeCount)) </strong>
        (ReactRe.stringToElement (" " ^ (activeCount === 1 ? "item" : "items") ^ " left"))
      </span>
      <Filters selected=filter />
      clearButton
    </footer>;
  }
};

include ReactRe.CreateComponent NodoFooter;

let createElement ::items ::onClearCompleted ::children => wrapProps { items, onClearCompleted } ::children;
