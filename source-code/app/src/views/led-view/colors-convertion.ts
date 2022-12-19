export function HEXToRGB(h: string) {
  let r = 0
  let g = 0
  let b = 0

  let rStr = ''
  let gStr = ''
  let bStr = ''

  // 3 digits
  if (h.length == 4) {
    rStr = '0x' + h[1] + h[1]
    gStr = '0x' + h[2] + h[2]
    bStr = '0x' + h[3] + h[3]

    // 6 digits
  } else if (h.length == 7) {
    rStr = '0x' + h[1] + h[2]
    gStr = '0x' + h[3] + h[4]
    bStr = '0x' + h[5] + h[6]
  }

  return { r: parseInt(rStr), g: parseInt(gStr), b: parseInt(bStr) }
}

export function HEXToRGBString(h: string) {
  const { r, g, b } = HEXToRGB(h)
  return 'rgb(' + +r + ',' + +g + ',' + +b + ')'
}

export function RGBToHSL(r: number, g: number, b: number) {
  // Make r, g, and b fractions of 1
  r /= 255
  g /= 255
  b /= 255

  // Find greatest and smallest channel values
  let cmin = Math.min(r, g, b),
    cmax = Math.max(r, g, b),
    delta = cmax - cmin,
    h = 0,
    s = 0,
    l = 0
  // Calculate hue
  // No difference
  if (delta == 0) h = 0
  // Red is max
  else if (cmax == r) h = ((g - b) / delta) % 6
  // Green is max
  else if (cmax == g) h = (b - r) / delta + 2
  // Blue is max
  else h = (r - g) / delta + 4

  h = Math.round(h * 60)

  // Make negative hues positive behind 360°
  if (h < 0) h += 360
  l = (cmax + cmin) / 2

  // Calculate saturation
  s = delta == 0 ? 0 : delta / (1 - Math.abs(2 * l - 1))

  // Multiply l and s by 100
  s = +(s * 100).toFixed(1)
  l = +(l * 100).toFixed(1)
  return { h, s, l }
}

export function RGBToHSLString(r: number, g: number, b: number) {
  const { h, s, l } = RGBToHSL(r, g, b)
  return 'hsl(' + h + ',' + s + '%,' + l + '%)'
}
