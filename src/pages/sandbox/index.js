import React from "react";
import Layout from '../../components/Layout'

import Hero from '../../components/Hero'
import Project from '../../components/Project.bs'

const header = {
  header: 'Projects & Sandbox',
  subheader: 'Here Be Dragons!'
}

const projects = [
  {
    title: 'EEVET',
    date: '2016-Now',
    url: 'https://eevet.com',
    tagline: 'Fair and easy event booking and payment management.',
    position: 'CTO',
    description: 'Former Event Escrow. This project has a complex ' +
    'infrastructure, combining a Machine Learning recommender in Python and ' +
    'R, a backend in Django, a frontend in Angular, and third party ' +
    'services like Stripe and Pipedrive.',
  },
  {
    title: 'WEBDATAIOT',
    date: '2018-Now',
    url: 'https://webdataiot.com',
    tagline: 'Hyper-optimized web experiences',
    position: 'CTO',
    description: 'This project aims to quickly create and deploy apps for ' +
    'its customers, then optimize its layout and content base on Machine ' +
    'Learning analysis of the customer\'s auience\'s social media interactions.'
  },
  {
    title: 'Manejo',
    date: '2019-Now',
    url: 'https://manejo.com.mx',
    tagline: 'Driving information and tips, from the Reforma driving school in Mexico',
    position: 'Lead Developer',
    description: 'GatsbyJS ReactJS app, with components in ReasonML, and ' +
    'data from/to GraphQL queries and mutations.'
  },
  {
    title: 'Event Escrow',
    date: '2016',
    url: 'https://eevet.com',
    tagline: 'Escrow service for live entertainment. The base for EEVET.',
    position: 'Lead Developer',
    description: 'Django app that used Stripe managed accounts for its ' +
    'customers to hold the event funds in escrow, and release or arbitrate ' +
    'them at the end of the event.'
  },
  {
    title: 'Parlevel VMS',
    date: '2016',
    url: 'https://chowtime.parlevelvms.com',
    tagline: 'Powerful solutions for Vending, Micro Market, and Office Coffee operations.',
    position: 'Fill Stack Developer',
    description: 'App optimizing inventory in vending machines, micro ' +
    'markets and office snacks. Developed in Laravel, with AngularJS elements'
  },
  {
    title: 'Life is Stories',
    date: '2015',
    url: 'https://lifeisstories.com',
    tagline: 'Life is stories. Save the ones that matter.',
    position: 'Lead Developer',
    description: 'Ruby on Rails app with AngularJS and JQuery.'
  },
  {
    title: 'KAPx',
    date: '2012-2014',
    url: 'https://opencollege.kaplan.com',
    tagline: 'Online degree programs, from Kaplan Inc.',
    position: 'Full Stack Developer',
    description: 'A complex infrastructure with a customer-facing python ' +
    'app in Google App ENgine, asynchronous lessons in a Moodle (PHP) ' +
    'backend, live and recorded video lessons on Adobe Media Servers on ' +
    'AWS, and Python backend on Google App Engine.'
  },
  {
    title: 'El Buen Fin',
    date: '2013',
    url: 'https://www.elbuenfin.org/',
    tagline: 'The Black Friday of Mexico',
    position: 'Lead Developer',
    description: 'App in Golang on Google App Engine.'
  },
  {
    title: 'Deseos 2013',
    date: '2012',
    url: 'https://apps.facebook.com/miseleccion-deseos/',
    tagline: 'Send New Year wishes to the Mexican national soccer team.',
    position: 'Lead Developer',
    description: 'Facebook app in Ruby, custom CRM in PHP.'
  },
]

export default class Index extends React.Component {
  constructor(props) {
    super(props);
    this.state = { isValidated: false };
  }

  render() {
    return (
      <Layout>
        <Hero content={header} />
        <div className="container">
          <h1 className="is-size-2">Projects</h1>
          <div className="columns is-multiline">
            {projects
                  .map((project, index) => (
                      <div className="column is-one-third-desktop" key={index}>
                        <Project project={project} index={index} />
                      </div>
                  ))}
          </div>
        </div>
      </Layout>
    );
  }
}
