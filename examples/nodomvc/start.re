type state = {
    mutable items: list NodoItem.t,
    mutable selected: option string
};

let state: state = {
  selected: None,
  items: [{
    id: "1",
    title: "Item 1",
    completed: false,
    created: ReasonJs.Date.make ()
  }, {
    id: "2",
    title: "Item 2",
    completed: true,
    created: ReasonJs.Date.make ()
  }]
};

let render () => {
  let { items, selected } = state;

  ReactDOMRe.render
    <NodoApp items selected />
    (ReasonJs.Document.getElementById "nodoapp");
};

let router = Director.Router.make [
  ("/", fun _ => {
    state.selected = None;
    render ()
  }),
  (":id", fun id => {
    state.selected = Some id;
    render ()
  })
];

Director.Router.init router;
render ();
