let component = ReasonReact.statelessComponent("TodoItem");

let make = (~item: ItemData.item, _children) => {
    ...component,
    render: (_self) => {
      <div className="item">
        <input 
          _type="checkbox"
          checked=(Js.Boolean.to_js_boolean(item.completed))
        />
        (ReasonReact.stringToElement(item.title))
      </div>
    }
}