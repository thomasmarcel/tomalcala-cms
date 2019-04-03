import React from "react";
import Layout from '../../components/Layout'

import Contact from '../../components/Contact'

export default class Index extends React.Component {
  constructor(props) {
    super(props);
    this.state = { isValidated: false };
  }

  render() {
    return (
      <Layout>
        <Contact />
      </Layout>
    );
  }
}
