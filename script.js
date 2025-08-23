// เลือก element ปุ่มสลับโหมดสี
const modeToggle = document.getElementById("modeToggle");
const body = document.body;

// เมื่อกดปุ่มให้สลับ class "dark-mode"
modeToggle.addEventListener("click", () => {
    body.classList.toggle("dark-mode");

    // เปลี่ยนสัญลักษณ์ปุ่มตามโหมด
    if(body.classList.contains("dark-mode")){
        modeToggle.textContent = "☀️";
    } else {
        modeToggle.textContent = "🌙";
    }
});

// ปุ่มกลับบนสุด
const scrollTopBtn = document.getElementById("scrollTopBtn");

// แสดงปุ่มเมื่อเลื่อนลง
window.onscroll = function() {
    if (document.documentElement.scrollTop > 200) {
        scrollTopBtn.style.display = "block";
    } else {
        scrollTopBtn.style.display = "none";
    }
};

// คลิกแล้วเลื่อนขึ้นบนสุด
scrollTopBtn.addEventListener("click", () => {
    window.scrollTo({ top: 0, behavior: "smooth" });
});