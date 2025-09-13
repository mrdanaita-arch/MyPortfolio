
const modeToggle = document.getElementById("modeToggle");
const body = document.body;


modeToggle.addEventListener("click", () => {
    body.classList.toggle("dark-mode");


    if(body.classList.contains("dark-mode")){
        modeToggle.textContent = "☀️";
    } else {
        modeToggle.textContent = "🌙";
    }
});


const scrollTopBtn = document.getElementById("scrollTopBtn");


window.onscroll = function() {
    if (document.documentElement.scrollTop > 200) {
        scrollTopBtn.style.display = "block";
    } else {
        scrollTopBtn.style.display = "none";
    }
};


scrollTopBtn.addEventListener("click", () => {
    window.scrollTo({ top: 0, behavior: "smooth" });
});