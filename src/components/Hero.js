import React from 'react'
import PropTypes from 'prop-types'

const Hero = ({ content }) => {
  const { title, subtitle } = content
  return (
    <section className="hero is-primary is-medium">
      <div className="hero-body">
        <div className="container">
          <h1 className="title">
            {title}
          </h1>
          <h2 className="subtitle">
            {subtitle}
          </h2>
        </div>
      </div>
    </section>
  )
}

Hero.propTypes = {
  content: PropTypes.shape({
      title: PropTypes.string,
      subtitle: PropTypes.string,
    })
}

export default Hero
