import React from "react";
import Layout from '../../components/Layout'

import Hero from '../../components/Hero'

const header = {
  header: 'Projects & Sandbox',
  subheader: 'Here Be Dragons!'
}

export default class Index extends React.Component {
  constructor(props) {
    super(props);
    this.state = { isValidated: false };
  }

  render() {
    return (
      <Layout>
        <Hero content={header} />
      </Layout>
    );
  }
}
