module NodoApp = {
  include ReactRe.Component.Stateful;
  let name = "NodoPage";

  type props = {
    items: list NodoItem.t,
    selected: option string
  };
  type state = {
    filter: Filter.t
  };

  let getInitialState props => {
    filter: All
  };

  let setFilter {state} filter => Some { filter: filter };

  let render {props, state, updater} => {
    let { items, selected } = props;
    let { filter } = state;

    <div>
      <Header />
      <MainSection items filter selected />
      <NodoFooter
        items
        filter
        onFilterChanged=(updater setFilter)
        onClearCompleted=(fun e => Js.log "clear!!")
      />
    </div>
  };
};

include ReactRe.CreateComponent NodoApp;
let createElement ::items ::selected ::children =>
  wrapProps { items, selected } ::children;
