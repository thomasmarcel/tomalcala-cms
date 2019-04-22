import React from 'react'
import PropTypes from 'prop-types'

const Hero = ({ content }) => {
  const { header, subheader } = content
  return (
    <section className="jumbotron hero is-medium">
      <div className="bg-image hero0">
        <div className="layer opacity-dark" />
      </div>
      <div className="hero-body" style={{paddingTop: '7rem', paddingBottom: '7rem'}}>
        <div className="container">
          <h1 className="header is-size-1">
            {header}
          </h1>
          <h2 className="subheader is-size-5">
            {subheader}
          </h2>
        </div>
      </div>
    </section>
  )
}

Hero.propTypes = {
  content: PropTypes.shape({
      header: PropTypes.string,
      subheader: PropTypes.string,
    })
}

export default Hero
