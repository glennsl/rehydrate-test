let getInitialState props => {
  let todos =
    switch (LocalStorage.get ()) {
      | None => [Todo.make "Item 1", Todo.make "Item 2"]
      | Some todos => ReasonJs.JSON.parse todos
    };
  State.({ selected: None, todos })
};

let store = Store.make (getInitialState ());
Store.subscribe store (fun state => LocalStorage.set state.todos);

let render (state) => {
  open State;
  let { todos, selected } = state;

  ReactDOMRe.render
    <NodoApp items=todos selected store />
    (ReasonJs.Document.getElementById "nodoapp");
};

let router = Director.Router.make [
  ("/", fun _ => Store.select store None),
  (":id", fun id => Store.select store (Some id))
];

Director.Router.init router;
Store.subscribe store render;
