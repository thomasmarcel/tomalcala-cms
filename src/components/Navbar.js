import React from 'react'
import { Link } from 'gatsby'
// import github from '../img/github-icon.svg'
// import logo from '../img/logo.svg'

const Navbar = class extends React.Component {

  componentDidMount() {
    // Get all "navbar-burger" elements
   const $navbarBurgers = Array.prototype.slice.call(document.querySelectorAll('.navbar-burger'), 0);
    // Check if there are any navbar burgers
   if ($navbarBurgers.length > 0) {
 
     // Add a click event on each of them
     $navbarBurgers.forEach( el => {
       el.addEventListener('click', () => {
 
         // Get the target from the "data-target" attribute
         const target = el.dataset.target;
         const $target = document.getElementById(target);
 
         // Toggle the "is-active" class on both the "navbar-burger" and the "navbar-menu"
         el.classList.toggle('is-active');
         $target.classList.toggle('is-active');
 
       });
     });
   }
 }
 
 render() {
   return (
  
  <nav className="navbar is-transparent" role="navigation" aria-label="main-navigation">
    <div className="container is-fluid">
      <div className="navbar-brand">
        <Link to="/" className="navbar-item" title="Logo">
          <i className="fab fa-empire fa-2x" />&nbsp;
          <b>Tom</b>Alcala
          {/* <img src={logo} alt="Kaldi" style={{ width: '88px' }} /> */}
            {/* <img src={logo} alt="Kaldi" style={{ width: '88px' }} /> */}
        </Link>
        {/* Hamburger menu */}
        <div className="navbar-burger burger" data-target="navMenu">
          <span></span>
          <span></span>
          <span></span>
        </div>
      </div>
      <div id="navMenu" className="navbar-menu">
      <div className="navbar-start has-text-centered">
        <Link className="navbar-item" to="/about">
          About
        </Link>
        <Link className="navbar-item" to="/contact">
          Contact
        </Link>
        <a className="navbar-item" href="/img/thomas_alcala-cv-201901-en-m.pdf" target="_blank">
          Resume
        </a>
        <Link className="navbar-item" to="/sandbox">
          Projects &amp; Sandbox
        </Link>
      </div>
      <div className="navbar-end has-text-centered">
        <a
          className="navbar-item"
          href="https://github.com/ThomasMarcel/tomalcala-cms"
          target="_blank"
          rel="noopener noreferrer"
        >
          Curious About the Source Code?
          <i className="fab fa-github" />
        </a>
      </div>
      </div>
    </div>
  </nav>
  )}
}

export default Navbar
