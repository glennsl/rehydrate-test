module NodoApp = {
  include ReactRe.Component.Stateful;
  let name = "NodoPage";

  type props = {
    todos: list NodoItem.item
  };
  type state = {
    filter: Filter.t
  };

  let getInitialState props => {
    filter: All
  };

  let setFilter {state} filter => Some { filter: filter };

  let render {props, state, updater} => {
    let { filter } = state;

    <div>
      <Header />
      <MainSection items=props.todos filter />
      <NodoFooter items=props.todos filter onFilterChanged=(updater setFilter) onClearCompleted=(fun e => Js.log "clear!!") />
    </div>
  };
};

include ReactRe.CreateComponent NodoApp;
let createElement ::todos ::children =>
  wrapProps { todos: todos } ::children;
