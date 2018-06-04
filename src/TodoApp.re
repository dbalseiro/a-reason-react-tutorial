type state = {
  items: list(ItemData.item)
};

type action =
  | AddItem(string);

let str = ReasonReact.stringToElement;

let component = ReasonReact.reducerComponent("TodoApp");

let newItem = itemText => ItemData.{
  title: itemText,
  completed: false
};

let make = _children => {
  ...component,

  initialState: () => {
    items: [
      { 
        title: "Write something",
        completed: false
      }
    ]
  },

  reducer: (action, {items}) => {
    switch action {
    | AddItem(itemText) => ReasonReact.Update({items: [newItem(itemText), ...items]})
    };
  },

  render: ({state} as self) => {
    let numItems = List.length(state.items);
    let itemDescription = numItems > 1 ? " items" : " item";

    <div className="app">
      <div className="title"> (str("What to do")) </div>
      <button onClick=((_evt) => self.send(AddItem("some text")))>
        (str("Add something"))
      </button>
      (state.items
        |> List.map((item) => <TodoItem item />)
        |> Array.of_list
        |> ReasonReact.arrayToElement
      )
      <div className="footer"> (str(string_of_int(numItems) ++ itemDescription)) </div>
    </div>
  }
};