import React from "react";
import Layout from '../../components/Layout'

import Hero from '../../components/Hero'
import Contact from '../../components/Contact'

const header = {
  header: 'Contact',
  subheader: 'Send Tom a Message!'
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
        <Contact />
      </Layout>
    );
  }
}
