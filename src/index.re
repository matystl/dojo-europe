Fetcher.fetchGet(
  ~url="https://immense-river-25513.herokuapp.com/locations", ~cb=markers => {
  let arrayOfLocations: array((float, float)) =
    Array.map(m => Fetcher.(m.location), markers);
  ReactDOMRe.renderToElementWithId(
    <BasicMap markers=arrayOfLocations />,
    "main",
  );
});