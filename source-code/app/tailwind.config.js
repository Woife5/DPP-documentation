const colors = require('tailwindcss/colors')

/** @type {import('tailwindcss').Config} */
module.exports = {
  content: ['./index.html', './src/**/*.{ts,vue}'],
  theme: {
    extend: {
      colors: {
        light: {
          dialog: {
            backdrop: 'hsla(0, 0%, 10%, 0.75)',
          },
        },
        dark: {
          dialog: {
            backdrop: 'hsla(0, 0%, 80%, 0.25)',
          },
        },
      },
      textColor: {
        dark: {
          success: colors.green[400],
          warn: colors.yellow[400],
          error: colors.red[400],
        },
        light: {
          success: colors.green[600],
          warn: colors.yellow[600],
          error: colors.red[600],
        },
      },
      animation: {
        vibrate: 'vibrate 100ms ease-in-out infinite',
        shake:
          'shakeX 100ms ease-in-out infinite, shakeY 100ms ease-in-out infinite',
        'spin-slow': 'spin 5s linear infinite',
      },
      keyframes: {
        vibrate: {
          '0%, 100%': { transform: 'rotate(-5deg)' },
          '50%': { transform: 'rotate(5deg)' },
        },
        shakeX: {
          '0%, 100%': { transform: 'translate3d(0px, 0px, 0)' },
          '25%': { transform: 'translate3d(6px, 0px, 0)' },
          '50%': { transform: 'translate3d(6px, 6px, 0)' },
          '75%': { transform: 'translate3d(0px, 6px, 0)' },
        },
      },
      fontFamily: {
        roboto: ['Roboto', 'sans-serif'],
        cairo: ['Cairo', 'sans-serif'],
        righteous: ['Righteous', 'sans-serif'],
        oxanium: ['Oxanium', 'sans-serif'],
        indieflower: ['Indie Flower', 'sans-serif'],
        oxanium: ['Oxanium', 'sans-serif'],
      },
    },
  },
  plugins: [],
}
