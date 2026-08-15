project = 'Contests'
copyright = '2025-2026, Lê Quốc Dũng'
author = 'Lê Quốc Dũng'
version = "1.0"

extensions = [
    'sphinx_togglebutton', 
    'sphinx_design', 
    'sphinx_book_theme', 
    'sphinx_proof', 
    'sphinxcontrib.bibtex',
    'sphinx.ext.graphviz'
]

disqus_shortname = "math-book"

language = "vi"

proof_minimal_theme = True

bibtex_bibfiles = ["myrefs.bib", "crypto.bib"]

html_logo = "rhine_lab.jpg"
html_title = "Contests"
html_theme = 'furo'
html_static_path = ['_static']
html_css_files = ['mystyles.css']

only_build_toc_files = True

graphviz_output_format = "svg"

mathjax3_config = {                  
    "tex": {                        
        "macros": {                     
            "bm": ['{\\boldsymbol{#1}}',1],
            "wt": r'\operatorname{wt}',
            "tr": r'\operatorname{tr}',
            "rank": r'\operatorname{rank}',
            "lcm": r"\mathrm{lcm}",
            "GL": r"\mathrm{GL}",
            "lex": r"\text{lex}",
            "grlex": r"\text{grlex}",
            "grevlex": r"\text{grevlex}",
            "CC": r"\mathbb{C}",
            "RR": r"\mathbb{R}",
            "QQ": r"\mathbb{Q}",
            "ZZ": r"\mathbb{Z}",
            "NN": r"\mathbb{N}",
            "FF": r"\mathbb{F}",
            "KK": r"\mathbb{K}"
            }                       
        },
    "chtml": {
        "mtextInheritFont": "true"
    }
}

numfig_format = {
    "figure": 'Hình %s',
    "table": 'Bảng %s'
}

numfig = True
pygments_style = "default"

exclude_patterns = [
    '_build', 'Thumbs.db', '.DS_Store', # default
    '2025/nsucrypto/*',
    '2025/yaprofi/*'
]
