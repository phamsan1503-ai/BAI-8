# Bài 8: Chuyển đổi ADC

## Yêu cầu
- Đọc và chuyển đổi tín hiệu **analog** sang dạng **số**.
- Cấu hình **một kênh ADC** để đọc giá trị từ:
  - Biến trở, hoặc
  - Cảm biến nhiệt độ.
- Chuyển đổi giá trị ADC này thành **điện áp (mV)**.
- Hiển thị giá trị điện áp lên **terminal (UART)**.

## Gợi ý triển khai
1. Khởi tạo và cấu hình ngoại vi **ADC** (ví dụ ADC1 channel x).
2. Khởi tạo và cấu hình ngoại vi **USART** để gửi dữ liệu lên terminal.
3. Thực hiện vòng lặp:
   - Đọc giá trị ADC 12-bit.
   - Quy đổi sang điện áp theo công thức:

     ```
     V_mV = (ADC_value * Vref_mV) / 4095
     ```

     với `Vref_mV = 3300 mV` (nếu Vref = 3.3V).

   - Gửi kết quả điện áp qua UART để hiển thị trên terminal.

---

📌 Sau khi code xong, bạn có thể build & chạy trên STM32F103 (hoặc vi điều khiển tương tự) để test bằng biến trở / cảm biến nhiệt độ.
