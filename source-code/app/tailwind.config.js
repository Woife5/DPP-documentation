/** @type {import('tailwindcss').Config} */
module.exports = {
  content: ['./index.html', './src/**/*.{ts,vue}'],
  theme: {
    extend: {
      animation: {
        wiggle: 'wiggle 300ms ease-in-out infinite',
        vibrate: 'wiggle 100ms ease-in-out infinite',
        'spin-slow': 'spin 5s linear infinite',
      },
      keyframes: {
        wiggle: {
          '0%, 100%': { transform: 'rotate(-5deg)' },
          '50%': { transform: 'rotate(5deg)' },
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
