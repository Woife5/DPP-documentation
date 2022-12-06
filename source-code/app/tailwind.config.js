/** @type {import('tailwindcss').Config} */
module.exports = {
  content: ['./index.html', './src/**/*.{ts,vue}'],
  theme: {
    extend: {
      animation: {
        wiggle: 'wiggle 300ms ease-in-out infinite',
        'spin-slow': 'spin 5s linear infinite',
      },
      keyframes: {
        wiggle: {
          '0%, 100%': { transform: 'rotate(-3deg)' },
          '50%': { transform: 'rotate(3deg)' },
        },
      },
    },
  },
  plugins: [],
}
