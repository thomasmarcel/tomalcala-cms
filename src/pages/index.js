import React from 'react'
import PropTypes from 'prop-types'
import { graphql } from 'gatsby'
import Layout from '../components/Layout'
import Hero from '../components/Hero'
import Contact from '../components/Contact'
import Post from '../components/Post.bs'

const content = {
  header: 'Hello and Welcome!',
  subheader: "This is my personal portfolio and sandbox to test new tools, frameworks, etc, everything development-related that sounds cool, and that I have time for..."
}

export default class IndexPage extends React.Component {
  render() {
    const { data } = this.props
    const { edges: posts } = data.allMarkdownRemark

    return (
      <Layout>
        <Hero content={content} />
        <div className="wide container is-fluid">
          <div className="content">
            <h1 className="has-text-weight-bold is-size-2">
              <i className="fas fa-rocket" />&nbsp;
              Latest Stories
            </h1>
          </div>
          {posts
            .map(({ node: post }, index) => (
              <div key={post.id} >
                <Post post={post} index={index} />
              </div>
            ))}
        </div>
        <Contact />
      </Layout>
    )
  }
}

IndexPage.propTypes = {
  data: PropTypes.shape({
    allMarkdownRemark: PropTypes.shape({
      edges: PropTypes.array,
    }),
  }),
}

export const pageQuery = graphql`
  query IndexQuery {
    allMarkdownRemark(
      sort: { order: DESC, fields: [frontmatter___date] },
      filter: { frontmatter: { templateKey: { eq: "blog-post" } }}
    ) {
      edges {
        node {
          excerpt(pruneLength: 400)
          id
          fields {
            slug
          }
          frontmatter {
            title
            templateKey
            date(formatString: "MMMM DD, YYYY")
          }
        }
      }
    }
  }
`
