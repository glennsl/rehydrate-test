module NodoApp = {
  include ReactRe.Component.Stateful;
  let name = "NodoPage";

  type props = {
    items: list Todo.t,
    selected: option string,
    store: Store.t
  };
  type state = {
    filter: Filter.t
  };

  let getInitialState props => {
    filter: All
  };

  let setFilter {state} filter => Some { filter: filter };

  let render {props, state, updater} => {
    let { items, selected, store } = props;
    let { filter } = state;

    <div>
      <Header store />
      <MainSection items filter selected store />
      <NodoFooter
        items
        filter
        onFilterChanged=(updater setFilter)
        onClearCompleted=(fun e => Store.clearCompleted store)
      />
    </div>
  };
};

include ReactRe.CreateComponent NodoApp;
let createElement ::items ::selected ::store ::children =>
  wrapProps { items, selected, store } ::children;
