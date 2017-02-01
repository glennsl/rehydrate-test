let todos: list NodoItem.item = [{
  id: "1",
  title: "Item 1",
  completed: false
}, {
  id: "2",
  title: "Item 2",
  completed: true
}];

ReactDOMRe.render <NodoApp todos=todos /> (ReasonJs.Document.getElementById "nodoapp");
