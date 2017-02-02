type t = {
  mutable state: State.t,
  mutable subscribers: list (State.t => unit)
};

let make state => {
  state,
  subscribers: []
};

let subscribe store subscriber => {
  store.subscribers = [subscriber, ...store.subscribers];
  subscriber store.state;
};

let rec notify state => fun
| [] => ()
| [subscriber, ...subscribers] => {
  subscriber state;
  notify state subscribers;
};

let updateStore store f => {
  store.state = f store.state;
  notify store.state store.subscribers;
};

/* Store actions */
let add store title =>
  updateStore store (fun state => {
    ...state,
    todos: [Todo.make title, ...state.todos]
  });

let replace store todo newTodo =>
  updateStore store (fun state => {
    ...state,
    todos: state.todos |> List.map (fun t => t === todo ? newTodo : t )
  });

let remove store todo =>
  updateStore store (fun state => {
    ...state,
    todos: state.todos |> List.filter (fun t => t !== todo)
  });

let update store todo title =>
  Todo.(replace store todo { ...todo, title });

let toggle store todo =>
  Todo.(replace store todo { ...todo, completed: not todo.completed });

let toggleAll store completed => Todo.(
  updateStore store (fun state => {
    ...state,
    todos: state.todos |> List.map (fun t => { ...t, completed })
  })
);

let clearCompleted store => Todo.(
  updateStore store (fun state => {
    ...state,
    todos: state.todos |> List.filter (fun t => not t.completed)
  })
);

let select store selected =>
  updateStore store (fun state => { ...state, selected });
