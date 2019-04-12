---
templateKey: blog-post
title: ReasonReact Interop Upgrade to API 0.7
date: 2019-04-12T02:25:57.988Z
description: Rewriting ReasonReact components called from ReactJS components.
tags:
  - React
  - ReasonReact
  - ReasonML
  - BuckleScript
---
Hey!

So as you may know, ReasonReact 0.7 is out! And it looks really awesome and a lot better at interacting with JS code, which is a GREAT idea, as it was kinda tricky to work with, the wrapping for JS was sketchy, as were props, and the overall look of the stateless and reducer components was going in a different direction than ReactJS update.

So now the new ReasonReact is out, using ReactJS hooks instead of the "deprecated" "Record API" as the ReasonReact people call the old syntax and bindings. This is cool, but raised some concerns in my mind as to how to upgrade my old components, and as expected, there isn't an automated way to do so because of the significant differences between both APIs.

I personally have a bunch of projects using Gatsby and Next.js frameworks with components written in ReasonReact that are at a state of active development, or post production features and enhancements stage, so I had to upgrade them. I am going to detail how I did so at a project and component scope, for future reference.

## Upgrade the Modules

First of all, let's upgrade the modules in **package.json**.

Locate the **bs-platform** module reference in **devDependencies**, and bump up the version to v5:

```
  "devDependencies": {      "bs-platform": "^5.0.1",
```

And under the **dependencies**, bump up **react**, **react-dom** and **reason-react**:

```
  "dependencies": {      "react": "^16.8.1",      "react-dom": "^16.8.1",      "reason-react": ">=0.7.0"  
```

And install (**npm run install** or **yarn install**).
