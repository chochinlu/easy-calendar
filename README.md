# easy-calendar

A simple calendar component. (powered by [reason-react](https://reasonml.github.io/reason-react/en/))

![screenshot](https://user-images.githubusercontent.com/1825273/45278533-20d11180-b500-11e8-9838-2407805a94d6.png)

## Testing

Clone this repo, then:

```txt
$ npm start
$ npm run webpack  // another terminal
$ open src/index.html // another terminal,  open reason-react version
$ open src/index.react.html  // open react version
```

## Usage ( for React )

The easy-calendar uses [mni.css](https://minicss.org/), please add the css binding before use the easy-calendar components:

```html
<link rel="stylesheet" href="https://cdn.rawgit.com/Chalarangelo/mini.css/v3.0.0/dist/mini-default.min.css">
<meta name="viewport" content="width=device-width, initial-scale=1">
```

Then:

```js
import { Calendar } from "easy-calendar";
```

## Target

- date picker. (done)
- day view (processing)
- year view, week view
- balabala.
